
<?php
        $host = 'localhost';
        $user = 'Raspi';
        $pass = 'pi';
        $database = 'raspiserver';
        $mysqli = new mysqli($host, $user, $pass, $database);

        // Check The Connection
        if($mysqli->connect_error){
                die("Connection failed: " . $mysqli->connect_error);
        }
        echo 'Connection success<br>';
?>
