# 🏦 Système Bancaire C++ avec Programmation Orientée Objet

## 📝 Présentation

Ce projet est une application console complète développée en C++ qui simule un système bancaire moderne avec une architecture orientée objet. Il offre une gestion complète des comptes clients, des opérations bancaires, un système d'authentification des utilisateurs, et même des fonctionnalités de conversion de devises.

## ✨ Fonctionnalités principales

- **Gestion complète des clients** : Ajouter, modifier, supprimer et rechercher des clients
- **Opérations bancaires** : Dépôts, retraits, transferts entre comptes
- **Système d'authentification** : Connexion sécurisée avec gestion des utilisateurs et permissions
- **Registre des opérations** : Historique des transferts et opérations effectuées
- **Conversion de devises** : Calculateur et échange de devises intégrés
- **Interface utilisateur structurée** : Navigation intuitive par menus

## 🗂️ Structure du Projet

Le projet est organisé selon les principes de la programmation orientée objet avec une séparation claire des responsabilités :

### Classes principales

- **clsPerson** : Classe de base contenant les informations personnelles
- **clsBankClient** : Gère les clients et leurs comptes (hérite de clsPerson)
- **clsUser** : Gestion des utilisateurs du système et leurs permissions
- **clsCurrency** : Gestion des devises et taux de change

### Écrans et Interface

- **clsScreen** : Classe de base pour tous les écrans
- **clsMainScreen** : Écran principal et point d'entrée du système
- **clsTransactionsScreen** : Écran pour les opérations bancaires
- **Écrans spécialisés** : Nombreuses classes dédiées (dépôt, retrait, transfert, etc.)

### Utilitaires

- **clsInputValidate** : Validation des entrées utilisateur
- **clsString** : Manipulation des chaînes de caractères
- **clsDate** : Gestion des dates et horodatage
- **clsUtil** : Fonctions utilitaires diverses

## 💾 Stockage des données

Les données sont persistantes et stockées dans plusieurs fichiers texte :
- **Clients.txt** : Informations sur les clients
- **Users.txt** : Utilisateurs du système et leurs permissions
- **Currencies.txt** : Liste des devises et taux de change
- **Transfer.txt** : Journal des opérations de transfert
- **Login.txt** : Registre des connexions

## 🚀 Installation et prérequis

### Prérequis

- Microsoft Visual Studio (2019 ou plus récent recommandé)
- Compilateur C++ compatible avec C++11 ou supérieur

### Installation

1. Clonez ou téléchargez le dépôt sur votre machine locale
2. Ouvrez le fichier solution `Bank Project OOP.sln` avec Visual Studio
3. Compilez le projet en mode Release ou Debug
4. Exécutez l'application

## 🎮 Guide d'utilisation

### Connexion

- Au démarrage, vous êtes invité à vous connecter avec un nom d'utilisateur et mot de passe
- Le système vérifie vos permissions et vous accorde l'accès aux fonctionnalités autorisées

### Menu Principal

Le menu principal propose plusieurs options :
1. **Liste des clients** : Affiche tous les clients de la banque
2. **Ajouter un client** : Créer un nouveau compte client
3. **Supprimer un client** : Supprimer un compte existant
4. **Mettre à jour un client** : Modifier les informations d'un client
5. **Rechercher un client** : Trouver un client par son numéro de compte
6. **Transactions** : Accéder au menu des opérations bancaires
7. **Gérer les utilisateurs** : Administrer les utilisateurs du système
8. **Registre des connexions** : Consulter l'historique des connexions
9. **Échange de devises** : Convertir et échanger des monnaies
10. **Déconnexion** : Quitter la session

### Menu Transactions

Ce menu permet d'effectuer toutes les opérations bancaires :
1. **Dépôt** : Ajouter des fonds à un compte
2. **Retrait** : Retirer des fonds d'un compte
3. **Soldes totaux** : Consulter les soldes de tous les comptes
4. **Transfert** : Transférer des fonds entre deux comptes
5. **Journal des transferts** : Consulter l'historique des transferts

## 🔒 Sécurité et validations

- Validation des entrées utilisateur pour prévenir les erreurs
- Système de permissions pour contrôler l'accès aux fonctionnalités
- Vérification des soldes avant les opérations de débit
- Journalisation des opérations sensibles

## 🧮 Concepts de POO implémentés

- **Héritage** : Organisation hiérarchique des classes (ex: clsBankClient hérite de clsPerson)
- **Encapsulation** : Protection des données avec accesseurs et mutateurs
- **Abstraction** : Interfaces utilisateur abstraites via clsScreen
- **Polymorphisme** : Comportements spécifiques pour différents types d'écrans
- **Classes et objets** : Structure orientée objet complète
- **Propriétés** : Utilisation de __declspec(property) pour une syntaxe élégante

## ⚙️ Extensibilité

Le système est conçu pour être facilement extensible :
- Ajout de nouvelles devises dans le fichier Currencies.txt
- Création de nouveaux types de transactions
- Extension des permissions utilisateur

## 👤 Auteur

- **Oussama Souissi** - Développeur du projet

## 📜 Licence

Ce projet est distribué sous licence open source.
