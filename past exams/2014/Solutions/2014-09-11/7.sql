-- 2014-09-11, 7

CREATE TABLE Teams (
     tname varchar(20) NOT NULL,
     tcountry varchar(3) NOT NULL,
     num_tf int,
     num_stf int,
     num_yj int
);

CREATE TABLE Stages (
     snumber int NOT NULL,
     sdate date NOT NULL,
     km real NOT NULL, -- decimal(6, x)
     scity varchar(30) NOT NULL,
     ecity varchar(30) NOT NULL
);

CREATE TABLE Riders (
     rname varchar(50) NOT NULL,
     rnum int NOT NULL,
     birthdate date NOT NULL,
     height int NOT NULL,
     weight real NOT NULL, -- decimal(6, x)
     rcountry varchar(3) NOT NULL,
     rcity varchar(20) NOT NULL,
     tname varchar(20) NOT NULL
);

CREATE TABLE Tour (
     id int NOT NULL,
     snumber int NOT NULL,
     rname varchar(50) NOT NULL,
     place int NOT NULL,
     points int NOT NULL,
     ttime time NOT NULL,
     white smallint NOT NULL, -- tinyint
	 yellow smallint NOT NULL, -- tinyint
     green smallint NOT NULL -- tinyint
);

-- Primary Key Constraints
ALTER TABLE Teams ADD CONSTRAINT PK_Teams PRIMARY KEY(tname);
ALTER TABLE Stages ADD CONSTRAINT PK_Stages PRIMARY KEY(snumber);
ALTER TABLE Riders ADD CONSTRAINT PK_Riders PRIMARY KEY(rname);
ALTER TABLE Tour ADD CONSTRAINT PK_Tour PRIMARY KEY(id);

-- Foreign Key Constraints
ALTER TABLE Riders ADD CONSTRAINT FK_Riders_Teams_name FOREIGN KEY(tname) REFERENCES Teams(tname);
ALTER TABLE Tour ADD CONSTRAINT FK_Tour_Stages_snumber FOREIGN KEY(snumber) REFERENCES Stages(snumber);
ALTER TABLE Tour ADD CONSTRAINT FK_Tour_Riders_rname FOREIGN KEY(rname) REFERENCES Riders(rname);

-- Integer constraints
ALTER TABLE Teams ADD CONSTRAINT Check_Positive_num_tf CHECK (num_tf > 0);
ALTER TABLE Teams ADD CONSTRAINT Check_Positive_num_stf CHECK (num_stf > 0);
ALTER TABLE Teams ADD CONSTRAINT Check_Positive_num_yj CHECK (num_yj > 0);
ALTER TABLE Stages ADD CONSTRAINT Check_Positive_snumber CHECK (snumber > 0);
ALTER TABLE Stages ADD CONSTRAINT Check_Positive_km CHECK (km > 0);
ALTER TABLE Riders ADD CONSTRAINT Check_Positive_rnum CHECK (rnum > 0);
ALTER TABLE Riders ADD CONSTRAINT Check_Positive_height CHECK (height > 0);
ALTER TABLE Riders ADD CONSTRAINT Check_Positive_weight CHECK (weight > 0);
ALTER TABLE Tour ADD CONSTRAINT Check_Positive_id CHECK (id > 0);
ALTER TABLE Tour ADD CONSTRAINT Check_Positive_place CHECK (place > 0);
ALTER TABLE Tour ADD CONSTRAINT Check_white CHECK (white = 0 OR white = 1);
ALTER TABLE Tour ADD CONSTRAINT Check_yellow CHECK (yellow = 0 OR yellow = 1);
ALTER TABLE Tour ADD CONSTRAINT Check_green CHECK (green = 0 OR green = 1);