<html>
    <head>
    <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <title>Mysite</title>

        <link rel="stylesheet" type="text/css" href="profileDesign.css">
    </head>

    <body>
        <div id="container">
            <?php
                if(isset($_POST['submit'])){
                    $imageName= $_FILES['Image']['name'];
                    $tmpName= $_FILES['Image']['tmp_name'];
                    $target_dir = "images/".$imageName;

                    move_uploaded_file($tmpName, $target_dir);
                }
            ?>

            <div class="left">
                <div class="lLeft">
                    <p><b>Name:</b></p>
                </div>

                <div class="lRight">
                    <p>
                        <?php 
                            echo $_POST["FirstName"]." ".$_POST['LastName']; 
                        ?>
                    </p>
                </div>

                <div class="lLeft">
                    <p><b>Email:</b></p>
                </div>

                <div class="lRight">
                    <p>
                        <?php 
                            echo $_POST["Email"];  
                        ?>
                    </p>
                </div>

                <div class="lLeft">
                    <p><b>Address:</b></p>
                </div>

                <div class="lRight">
                    <p>
                        <?php 
                            echo $_POST["Address"]; 
                        ?>
                    </p>
                </div>
            </div>

            <div class="right">
                <?php 
                    $imageName= $_FILES['Image']['name'];
                    $tmpName= $_FILES['Image']['tmp_name'];
                    $target_dir = "images/".$imageName;
                    echo "<img src='images/$imageName'>";
                ?>

            </div>

        </div>


    </body>
</html>