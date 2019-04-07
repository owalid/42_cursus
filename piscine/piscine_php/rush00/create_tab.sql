CREATE TABLE USERS(
        id_usr    Int  AUTO_INCREMENT  NOT NULL UNIQUE,
        firstname Varchar (50) NOT NULL ,
        lastname  Varchar (50) NOT NULL ,
        login     Varchar (50) NOT NULL UNIQUE,
        passwd    Varchar (516) NOT NULL ,
        email     Varchar (50) NOT NULL ,
        phone     Int NOT NULL ,
        birth     Date NOT NULL
	,CONSTRAINT USERS_PK PRIMARY KEY (id_usr)
);

CREATE TABLE Admin(
        id_usr    Int  AUTO_INCREMENT NOT NULL UNIQUE,
        firstname Varchar (50) NOT NULL ,
        lastname  Varchar (50) NOT NULL ,
        login     Varchar (50) NOT NULL ,
        passwd    Varchar (516) NOT NULL ,
        email     Varchar (50) NOT NULL ,
        phone     Int NOT NULL ,
        birth     Date NOT NULL
	,CONSTRAINT Admin_PK PRIMARY KEY (id_usr)

	,CONSTRAINT Admin_USERS_FK FOREIGN KEY (id_usr) REFERENCES USERS(id_usr)
);

CREATE TABLE Categorie(
        id_cat   Int  AUTO_INCREMENT   NOT NULL UNIQUE,
        name_cat Varchar (50) NOT NULL
	,CONSTRAINT Categorie_PK PRIMARY KEY (id_cat)
);

CREATE TABLE Produit(
        id_prod     Int  AUTO_INCREMENT   NOT NULL UNIQUE,
        label       Varchar (50) NOT NULL ,
        pieces      Int NOT NULL ,
        price       Int NOT NULL ,
        path_img    Varchar (300) NOT NULL ,
        description Varchar (50) NOT NULL ,
        id_cat      Int NOT NULL
	,CONSTRAINT Produit_PK PRIMARY KEY (id_prod)

	,CONSTRAINT Produit_Categorie_FK FOREIGN KEY (id_cat) REFERENCES Categorie(id_cat)
);

CREATE TABLE Transaction(
        id_trans     Int  AUTO_INCREMENT   NOT NULL UNIQUE,
        date_trans   Date NOT NULL ,
        amount_trans Float NOT NULL ,
        id_usr       Int NOT NULL
	,CONSTRAINT Transaction_PK PRIMARY KEY (id_trans)

	,CONSTRAINT Transaction_USERS_FK FOREIGN KEY (id_usr) REFERENCES USERS(id_usr)
);

CREATE TABLE commande(
        id_usr    Int AUTO_INCREMENT NOT NULL UNIQUE,
        id_prod   Int NOT NULL ,
        qty_order Int NOT NULL
	,CONSTRAINT commande_PK PRIMARY KEY (id_usr,id_prod)

	,CONSTRAINT commande_USERS_FK FOREIGN KEY (id_usr) REFERENCES USERS(id_usr)
	,CONSTRAINT commande_Produit0_FK FOREIGN KEY (id_prod) REFERENCES Produit(id_prod)
);

CREATE TABLE approvision(
        id_prod      Int AUTO_INCREMENT  NOT NULL UNIQUE,
        id_usr       Int NOT NULL ,
        id_appro     Int NOT NULL ,
        qty_reassort Int NOT NULL
	,CONSTRAINT approvision_PK PRIMARY KEY (id_prod,id_usr)

	,CONSTRAINT approvision_Produit_FK FOREIGN KEY (id_prod) REFERENCES Produit(id_prod)
	,CONSTRAINT approvision_Admin0_FK FOREIGN KEY (id_usr) REFERENCES Admin(id_usr)
);