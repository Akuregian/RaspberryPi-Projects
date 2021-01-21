<?php
        function RenderTables(){
        $servername = "localhost";
        $username = "Raspi";
        $password = "pi";
        $dbname = "raspiserver";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT * FROM Devices";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            echo "<table><tr><th>ID</th><th>Name</th><th>Description</th><th>Location</th><th>Status</th></tr>";
            // output data of each row
            while($row = $result->fetch_assoc()) {
                echo "<tr><td>" . $row["Device_id"]. "</td><td>". $row["Name"] . "</td><td>" .$row["Description"]. "</td> <td>" .$row["Location"]. "</td><td>" .$row["Status"]. "</td></tr>";
            }
            echo "</table>";
        } else {
            echo "0 results";
        }

        $conn->close();
        }

RenderTables();
?>
