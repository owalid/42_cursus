SELECT
  etage_salle AS 'etage',
  SUM(nbr_siege) AS 'siege'
FROM
  salle
GROUP BY
  etage_salle
ORDER BY
COUNT(nbr_siege) DESC;