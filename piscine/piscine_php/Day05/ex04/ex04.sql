UPDATE ft_table
SET date_de_creation = DateAdd(yy, 20, date_de_creation)
WHERE id > 5;