-- 2014-07-15, 7

CREATE TABLE Groups (
    gname varchar(1) NOT NULL,
    fplace varchar(20) NOT NULL,
    splace varchar(20) NOT NULL
);

CREATE TABLE Teams (
    country varchar(20) NOT NULL,
    gname varchar(1) NOT NULL,
    num_wc int NOT NULL
);

CREATE TABLE Players (
    pname varchar(50) NOT NULL,
    team varchar(20) NOT NULL,
    num_player smallint NOT NULL, -- tinyint
    num_goals int NOT NULL
);

CREATE TABLE Matches (
    mnumber int NOT NULL,
    tstage varchar(8) NOT NULL,
    stage varchar(3),
	team_host varchar(20) NOT NULL,
    team_guest varchar(20) NOT NULL,
    result varchar(1) NOT NULL,
    scores varchar(5) NOT NULL,
    date DATE NOT NULL,
    time TIME NOT NULL
);

ALTER TABLE Groups ADD CONSTRAINT PK_Groups PRIMARY KEY(gname);
ALTER TABLE Teams ADD CONSTRAINT PK_Teams PRIMARY KEY(country);
ALTER TABLE Players ADD CONSTRAINT PK_Players PRIMARY KEY(pname);
ALTER TABLE Matches ADD CONSTRAINT PK_Mathes PRIMARY KEY(mnumber);
ALTER TABLE Groups ADD CONSTRAINT FK_Groups_Teams_fplace FOREIGN KEY(fplace) REFERENCES Teams(country);
ALTER TABLE Groups ADD CONSTRAINT FK_Groups_Teams_splace FOREIGN KEY(splace) REFERENCES Teams(country);
ALTER TABLE Teams ADD CONSTRAINT FK_Teams_Groups FOREIGN KEY(gname) REFERENCES Groups(gname);
ALTER TABLE Players ADD CONSTRAINT FK_Players_Teams FOREIGN KEY(team) REFERENCES Teams(country);
ALTER TABLE Matches ADD CONSTRAINT FK_Matches_Teams_host FOREIGN KEY(team_host) REFERENCES Teams(country);
ALTER TABLE Matches ADD CONSTRAINT FK_Matches_Teams_guest FOREIGN KEY(team_guest) REFERENCES Teams(country);
ALTER TABLE Teams ADD CONSTRAINT CHK_Teams_num_wc CHECK (num_wc > 0);
ALTER TABLE Players ADD CONSTRAINT CHK_Players_num_player CHECK (num_player > 0 AND num_player < 23);
ALTER TABLE Players ADD CONSTRAINT CHK_Players_num_goals CHECK (num_goals > 0);
ALTER TABLE Matches ADD CONSTRAINT CHK_Matches_mnumber CHECK (mnumber > 0);