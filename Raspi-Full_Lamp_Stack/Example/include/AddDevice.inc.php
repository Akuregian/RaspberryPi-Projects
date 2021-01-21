<?php

        include_once 'database_connect.inc.php';

        $Name = $_POST['Name'];
        $Descript = $_POST['Description'];
        $Loc = $_POST['Location'];
        $State = $_POST['Status'];


        $sql = "INSERT INTO Devices (Name,  Description, Location, Status) VALUES ('$Name', '$Descript', '$Loc', '$State');";

        if(!mysqli_query($mysqli, $sql)) {
                echo 'Error has occured <br>';
                echo 'Error: ' . mysqli_error($conn);
                die();
        }

        header("Location: ../index.php?deviceAdded=success");
?>
