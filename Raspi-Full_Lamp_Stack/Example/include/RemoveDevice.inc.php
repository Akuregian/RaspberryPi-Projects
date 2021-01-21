
<?php
        include_once 'db.inc.php';
        $id = $_POST['id'];

//      $removeQuery = "DELETE FROM Devices WHERE id = {$id}";

        $removeQuery = "DELETE FROM Devices WHERE Device_id = {$id}";
        if(mysqli_query($mysqli, $removeQuery)) {
                echo "Record Deleted";
        }else{
                echo "Failed";
                die();
        }

        header("Location: ../index.php?deviceRemoved=success");
?>
