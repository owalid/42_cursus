INSERT INTO ft_table (login, groupe, date_de_creation)
    SELECT nom, groupe, date_de_creation
    FROM fiche_personne
    WHERE LEN(login) <= 9
    AND groupe = 'other'
    AND nom LIKE '%a%'
    ORDER BY nom
    LIMIT 10;