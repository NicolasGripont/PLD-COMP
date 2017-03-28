#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Erreur : Le nombre d'arguments est invalide"
	echo "Exemple : ./scriptTestAuto.sh ./../comp ./ValidPrograms/"
	echo "          scriptName       program   directory_containing_test_files"
else
	comp=$1
	dirname=$2

	for file in `ls $dirname` 
	 do
	 		echo "----------------------------------------------------------------"
	        echo ""
	 		echo "$1 ./tests/$dirname$file"
	 		echo ""
	        $comp $dirname$file
	        echo ""    
	done
	echo "----------------------------------------------------------------"
	echo ""
fi

