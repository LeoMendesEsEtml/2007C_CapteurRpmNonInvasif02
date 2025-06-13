# Capteur RPM Non Invasif pour Avion – Projet 2007C

## 📌 Description

Programme fonctionnel sur la carte **PCB2007C** développée dans le cadre du projet 2007C à l’**ETML-es**.  
L’objectif est de mesurer la vitesse de rotation des hélices d’un avion **sans contact** avec l’appareil, grâce à différents capteurs embarqués.

Trois types de mesures sont prévus :

- **Mesure visuelle** par capteur infrarouge
- **Mesure audio** par microphone (FFT)
- **Mesure de vibrations** via accéléromètre (FFT)

Interface utilisateur avec menu LCD, boutons OK / SELECT, profils enregistrables selon le type d’avion.

---

## 📍 Emplacement du projet
C:\microchip\harmony\v2_06\apps
(Oui pas en dessous de apps)

---

## 🛠️ Développement

- **IDE** : MPLAB X IDE 6.15  
- **Compilateur** : xc32 2.x  
- **Framework** : Harmony 2.06  
- **MCU** : PIC32MZ2048EFM064-I/PT  
- **Afficheur** : NHD-C0220BIZ-FSW-FBW-3V3M  
- **Technos** : ADC, PWM, IC, SPI, I2C, menu FSM, KissFFT

---

## ✅ État du développement

| Fonctionnalité                        | Statut |
|--------------------------------------|--------|
| Menu LCD complet                     | OK     |
| Sauvegarde NVM                       | ❌     |
| Lecture tension batterie             | ⚠️ partielle |
| Mesure RPM par IR                    | ✅ Preuve de concept validée |
| Mesure RPM par microphone            | ❌ Micro HS / Schéma à corriger |
| Mesure RPM par accéléromètre         | ❌ SPI instable |
| Auto-calibration IR                  | ⚠️ À implémenter |
| Communication USART (RS485 / USB)    | ❌ Non implémentée |
| FFT avec KissFFT                     | ⚠️ Tests partiels uniquement |

---

## 📂 Dépôt GitHub

[2007C_CapteurRpmNonInvasif02](https://github.com/LeoMendesEsEtml/2007C_CapteurRpmNonInvasif02)

---

## 👤 Auteur

- **Léo Mendes**
- Projet réalisé à l’**ETML-es**  
- Dates : **15.11.2024 – 20.06.2025**
- Supervision : **Juan José Moreno (Association AMPA)**

---

## 🧾 Remarques

Ce dépôt contient le firmware embarqué ainsi que les configurations MPLAB Harmony.  
Le code a été pensé pour être **évolutif**, avec gestion des profils, test de différentes technologies de détection, et validation terrain en cockpit.

---

## 🔧 À faire / Améliorations futures

- Refonte du routage PCB (corrections LDO / SPI / rainures)
- Intégration complète de l’accéléromètre via module piggyback
- Communication série active (pour FFT avec Octave)
- Menu plus robuste avec gestion d’erreurs
- Finalisation de la mesure IR avec réglage dynamique
- Ajout EEPROM externe pour sécuriser les profils


