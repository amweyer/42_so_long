#!/bin/bash

# Taille de la tuile (modifiable)
SIZE=64

# Dossier contenant les images (ici le dossier courant)
FOLDER=.

# Parcours de toutes les images XPM ou PNG du dossier
for img in "$FOLDER"/*.{xpm,png}; do
    # Vérifie que le fichier existe vraiment (évite les erreurs si aucun fichier)
    [ -e "$img" ] || continue

    # Nouveau nom de fichier (ex: wall.xpm -> wall_32.xpm)
    base=$(basename "$img")
    name="${base%.*}"
    ext="${base##*.}"
    newfile="${FOLDER}/${name}_${SIZE}.${ext}"

    # Redimensionnement
    convert "$img" -resize ${SIZE}x${SIZE}! "$newfile"

    echo "✅ $img redimensionné en $newfile"
done
