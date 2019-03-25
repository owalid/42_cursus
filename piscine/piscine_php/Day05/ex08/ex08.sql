SELECT nom, prenom, date_de_naissance
FROM fiche_personne
WHERE YEAR(date_naissance)=1989 
ORDER BY nom ASC