<!DOCTYPE html>
<html>
        <head>
                <title> Php Webpage Test </title>

                <h1 style="text-align:center;"> Welcome To my Raspberry Pi [L]inux [A]pache [M]ySQL [P]HP Website </h1>
                <style>
                table, th, td {
                    margin-left: auto;
                    margin-right: auto;
                    margin-top: auto;
                    border: 1px solid black;
                    font-size:40px
                }

                .container {
                    margin: auto;
                }
                .AddDevice{
                    height:40px;
                    width: 100px;
                    margin-left: 150px;
                    display: inline-block;
                }
                .RemoveDevice{
                    height:40px;
                    width: 100px;
                    margin-left: 200px;
                    display: inline-block;
                }
                h3{
                   text-align:center;
                   width: 250px;
                }
                </style>
        </head>

        <body>
            <h2 style="text-align:center;">List Of All Devices on the mySQL Server <h2>
                <?php
                        include 'include/RenderTables.inc.php'
                ?>
                <div class="container">
                        <div class="AddDevice">
                                <form action="include/AddDevice.inc.php" method="POST">
                                        <h3>Add A Device to Server <h3>
                                        <input type="text" name="Name" placeholder="Device Name">
                                        <br>
                                        <input type="text" name="Description" placeholder="Device Description">
                                        <br>
                                        <input type="text" name="Location" placeholder="Device Location">
                                        <br>
                                        <input type="number" name="Status" placeholder="Device Status">
                                        <br>
                                        <button type="submit", name="Submit">Submit</button>
                                </form>
                        </div>
                        <div class="RemoveDevice">
                                <form action="include/RemoveDevice.inc.php" method="POST">
                                        <h3>Remove A Device from the Server <h3>
                                        <input type="text" name="id" placeholder="Device ID Number">
                                        <br>
                                        <button onclick="AlertFunction()" type="submit", name="Submit">Submit</button>
                                </form>
                        </div>

                </div>
        <script> function AlertFunction(){
                alert("Are You Sure?")

        }
        </script>
        </body>
</html>
                                                 
