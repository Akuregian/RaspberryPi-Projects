
USE raspiserver; // Create This Using MYSQL 'CREATE DATABASE raspiserver;'

CREATE TABLE IF NOT EXISTS Devices (
        Device_id INT AUTO_INCREMENT PRIMARY KEY,
        Name VARCHAR(255) NOT NULL,
        Description VARCHAR(255) NOT NULL,
        Location VARCHAR(255) NOT NULL,
        Status BOOLEAN NOT NULL,
        Created_At TIMESTAMP DEFAULT CURRENT_TIMESTAMP

) ENGINE=INNODB;

