SELECT film.tite as 'Titre', film.resum as 'Resume'
FROM film
INNER JOIN genre ON film.id_genre = genre.id_genre
WHERE genre.nom = 'erotic'
ORDER BY film.annee_prod DESC