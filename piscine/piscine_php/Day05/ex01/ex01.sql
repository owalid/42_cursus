CREATE TABLE ft_table
(
    id INT PRIMARY KEY NOT NULL,
    login varhcar(9) DEFAULT 'toto',
    groupe ENUM('staff', 'student', 'other') NOT NULL,
    date_de_creation DATE NOT NULL,
)