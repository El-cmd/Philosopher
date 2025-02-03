# Philosophers

Ce projet est une implémentation du problème classique des philosophes dîneurs, un exercice de synchronisation en programmation concurrente.

## 🎯 Description du Projet

Le problème des philosophes dîneurs illustre les défis de la synchronisation dans les systèmes multithread. Des philosophes sont assis autour d'une table ronde, alternant entre manger et penser. Pour manger, chaque philosophe a besoin de deux fourchettes, une à sa gauche et une à sa droite.

## 🛠 Fonctionnalités

- Simulation de philosophes avec des threads POSIX
- Gestion des mutex pour les fourchettes
- Surveillance du temps de repas et de réflexion
- Détection de la mort d'un philosophe
- Gestion précise du timing avec des timestamps

## Structure du Projet

```
Philosophers/
├── includes/
│   └── philo.h          # Fichier d'en-tête principal
├── srcs/
│   ├── error_gestion.c  # Gestion des erreurs
│   ├── free_britney.c   # Gestion de la libération de mémoire
│   ├── init_thread.c    # Initialisation des threads
│   ├── mutex.c          # Gestion des mutex
│   ├── philo_data.c     # Gestion des données des philosophes
│   ├── print.c          # Fonctions d'affichage
│   ├── routine.c        # Routine des philosophes
│   ├── time.c           # Gestion du temps
│   └── utils.c          # Fonctions utilitaires
├── philo.c              # Point d'entrée du programme
├── Makefile             # Compilation du projet
└── readme.md            # Documentation du projet
```

## � Compilation et Exécution

```bash
make        # Pour compiler le programme
./philo [nombre_de_philosophes] [temps_pour_mourir] [temps_pour_manger] [temps_pour_dormir] [nombre_de_repas_optionnel]
```

### Arguments
- `nombre_de_philosophes`: Nombre de philosophes autour de la table
- `temps_pour_mourir`: Temps en millisecondes avant qu'un philosophe meure de faim
- `temps_pour_manger`: Temps en millisecondes nécessaire pour manger
- `temps_pour_dormir`: Temps en millisecondes que le philosophe passe à dormir
- `nombre_de_repas`: (Optionnel) Nombre de fois que chaque philosophe doit manger

## ⚠️ Gestion des Erreurs

Le programme inclut une gestion robuste des erreurs pour :
- Validation des arguments
- Création des threads
- Initialisation des mutex
- Allocation de mémoire

## 🎓 Projet 42

Ce projet fait partie du cursus de l'école 42, mettant l'accent sur la programmation système et la gestion des threads.