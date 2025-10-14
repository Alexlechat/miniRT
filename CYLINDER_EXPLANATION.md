# Gestion des Cylindres dans miniRT

## Vue d'ensemble

L'intersection rayon-cylindre est décomposée en **3 parties** :
1. Le **corps du cylindre** (surface latérale)
2. Le **cap inférieur** (disque à la base)
3. Le **cap supérieur** (disque au sommet)

---

## 1. Structure du Cylindre

```c
typedef struct s_cylinder {
    t_vector    position;      // Point de base du cylindre
    t_vector    orientation;   // Axe du cylindre (normalisé)
    double      radius;        // Rayon du cylindre
    double      height;        // Hauteur du cylindre
    t_color     color;         // Couleur
} t_cylinder;
```

**Représentation géométrique :**
- `position` : Point P₁ (base du cylindre)
- `position + orientation * height` : Point P₂ (sommet du cylindre)
- L'axe du cylindre va de P₁ à P₂

---

## 2. Intersection avec le Corps du Cylindre

### Méthode : Produit Vectoriel (Cross Product)

#### Étape 1 : Calcul de l'équation quadratique

Pour trouver l'intersection entre un rayon et un cylindre infini, on utilise :

```
u = ray_direction × cylinder_axis
v = (cylinder_position - ray_origin) × cylinder_axis
```

L'équation quadratique devient :
```
a·t² + b·t + c = 0

où :
a = u · u
b = 2 · (u · v)
c = v · v - radius²
```

**Pourquoi ça marche ?**
- Le produit vectoriel avec l'axe du cylindre projette le problème dans le plan perpendiculaire à l'axe
- On résout alors un problème 2D de distance à un point (l'axe)

#### Étape 2 : Résolution de l'équation

```c
delta = b² - 4ac

Si delta < 0 : Pas d'intersection
Si delta ≥ 0 :
    t₁ = (-b - √delta) / (2a)
    t₂ = (-b + √delta) / (2a)
```

#### Étape 3 : Validation des solutions

Pour chaque solution `t`, on vérifie :

1. **t > 0.001** : L'intersection est devant la caméra
2. **Projection sur l'axe** :
   ```c
   hit_point = ray_origin + ray_direction * t
   to_hit = hit_point - cylinder_position
   projection = to_hit · cylinder_axis
   
   Valide si : 0 ≤ projection ≤ height
   ```

#### Étape 4 : Calcul de la normale

La normale du cylindre pointe radialement vers l'extérieur :

```c
// 1. Projeter le point d'intersection sur l'axe
proj_len = (hit_point - cylinder_position) · cylinder_axis
proj_point = cylinder_position + cylinder_axis * proj_len

// 2. La normale va du point projeté vers le point d'intersection
normal = normalize(hit_point - proj_point)
```

---

## 3. Intersection avec les Caps (Disques)

Chaque cap est un **plan circulaire** perpendiculaire à l'axe du cylindre.

### Cap Inférieur
- Centre : `cylinder_position`
- Normale : `cylinder_axis` (pointant vers le haut)

### Cap Supérieur
- Centre : `cylinder_position + cylinder_axis * height`
- Normale : `cylinder_axis` (pointant vers le haut)

### Algorithme d'intersection rayon-cap

```c
// 1. Intersection rayon-plan
denom = ray_direction · cap_normal
t = (cap_center - ray_origin) · cap_normal / denom

// 2. Vérifier que t > 0.001

// 3. Calculer le point d'intersection
hit_point = ray_origin + ray_direction * t

// 4. Vérifier que le point est dans le disque
distance = ||hit_point - cap_center||
Valide si : distance ≤ radius
```

---

## 4. Fonction Principale : `cylinder_intersection()`

### Algorithme complet

```
1. Initialiser hit->distance = INFINITY

2. Tester le cap inférieur (P₁)
   Si intersection ET dans le disque ET plus proche :
       Mettre à jour hit

3. Tester le cap supérieur (P₂)
   Si intersection ET dans le disque ET plus proche :
       Mettre à jour hit

4. Tester le corps du cylindre
   Si intersection ET dans les limites de hauteur ET plus proche :
       Mettre à jour hit

5. Si hit->distance < INFINITY :
       hit->hit = true
       Retourner hit->distance
   Sinon :
       Retourner 0 (pas d'intersection)
```

### Pourquoi cet ordre ?

On teste **toutes les parties** et on garde **la plus proche**. Cela garantit :
- Pas de "trous" visuels
- Gestion correcte des cas où le rayon traverse plusieurs parties
- Rendu correct même avec des angles difficiles

---

## 5. Cas Particuliers

### Rayon parallèle à l'axe

Si `ray_direction × cylinder_axis ≈ 0` :
- Le rayon est parallèle à l'axe
- Pas d'intersection avec le corps (ou intersection à l'infini)
- On vérifie uniquement les caps

### Rayon perpendiculaire à l'axe

- Intersection avec le corps uniquement si le rayon passe dans la "tranche" du cylindre
- Les caps ne sont pas visibles de ce point de vue

### Cylindre très court (height ≈ 0)

- Se comporte presque comme un disque
- Le corps est très petit
- Les caps dominent visuellement

---

## 6. Optimisations

### Epsilon pour la précision numérique

```c
#define EPSILON 0.001
```

- Évite les auto-intersections (rayon qui part d'une surface)
- Évite les erreurs d'arrondi aux bords

### Test de `a < 1e-10`

```c
if (q.a < 1e-10)
    return false;
```

- Évite la division par zéro
- Gère le cas du rayon parallèle à l'axe

### Ordre des tests

On teste d'abord `solution_1` (plus proche) puis `solution_2` :
- Économise des calculs si la première solution est valide
- Important pour les performances avec beaucoup de cylindres

---

## 7. Exemple Visuel

```
        P₂ (sommet)
         •────────  Cap supérieur
         │        │
         │        │  Corps du cylindre
         │        │  (surface latérale)
         │        │
         •────────  Cap inférieur
        P₁ (base)
         
         ↑
    cylinder_axis
```

**Rayon traversant le cylindre :**
```
    Caméra
      ↓
      •
       \
        \  ← Rayon
         \
          •─────  Intersection 1 (entrée)
          │     │
          │  •  │ ← Intersection 2 (sortie)
          │     │
          •─────
```

On garde **Intersection 1** car c'est la plus proche de la caméra.

---

## 8. Résumé des Fonctions

| Fonction | Rôle |
|----------|------|
| `solve_quadratic()` | Résout l'équation at² + bt + c = 0 |
| `check_and_set_cyl_hit()` | Vérifie qu'une solution t est valide (distance, hauteur, normale) |
| `infinite_cyl_inter()` | Trouve l'intersection avec le corps du cylindre infini |
| `plane_inter_cap()` | Trouve l'intersection avec un plan (pour les caps) |
| `distance_vec()` | Calcule la distance entre deux points |
| `cylinder_intersection()` | Fonction principale qui combine tout |

---

## 9. Format dans le fichier .rt

```
cy  x,y,z  orient_x,orient_y,orient_z  diameter  height  r,g,b

Exemple :
cy  10,-20,40  0.5,1,0.5  10  20  10,0,255
```

- Position : (10, -20, 40)
- Orientation : (0.5, 1, 0.5) → sera normalisé automatiquement
- Diamètre : 10 → rayon = 5
- Hauteur : 20
- Couleur : RGB(10, 0, 255) - bleu violet

---

## 10. Points Clés à Retenir

✅ **Le cylindre a 3 parties** : corps + 2 caps
✅ **On teste toutes les parties** et on garde la plus proche
✅ **La normale du corps** est perpendiculaire à l'axe
✅ **La normale des caps** est parallèle à l'axe
✅ **Le produit vectoriel** simplifie les calculs
✅ **Les epsilon** évitent les bugs de précision numérique
