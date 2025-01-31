USE cs_350;
DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id       INT(11)      NOT NULL AUTO_INCREMENT,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    salt     VARCHAR(255) NOT NULL,
    PRIMARY KEY (id),
    UNIQUE KEY (username)
);