#!/bin/bash

# Fonction pour générer des nombres aléatoires
generate_random() {
    local min=$1
    local max=$2
    local count=$3
    local numbers=()
    
    # Créer un tableau avec tous les nombres possibles
    for ((i=min; i<=max; i++)); do
        numbers+=($i)
    done
    
    # Mélanger le tableau (algorithme Fisher-Yates)
    for ((i=${#numbers[@]}-1; i>0; i--)); do
        local j=$(($RANDOM % (i+1)))
        local temp=${numbers[i]}
        numbers[i]=${numbers[j]}
        numbers[j]=$temp
    done
    
    # Afficher les premiers 'count' nombres
    for ((i=0; i<count; i++)); do
        echo -n "${numbers[i]} "
    done
    echo
}

# Générer 100 nombres aléatoires de 1 à 100
generate_random 1 100 100 > shuffled.txt
#generate_random 1 500 500 > shuffled.txt

# Tester push_swap avec ces nombres
./push_swap $(cat shuffled.txt)