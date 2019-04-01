SELECT REVERSE(SUBSTRING(distrib.phone_number, 2, 10)) AS 'reb-munenohp'
FROM distrib
WHERE distrib.phone_number LIKE "05%"