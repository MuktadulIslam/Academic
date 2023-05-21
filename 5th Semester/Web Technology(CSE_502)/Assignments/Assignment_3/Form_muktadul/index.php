<!DOCTYPE HTML>
<html>

    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <title>Mysite</title>

        <link rel="stylesheet" type="text/css" href="formDesign.css">
    </head>

    <body>
        <form action="profile.php" method="post" enctype="multipart/form-data">
            <div id="container">
                <div class="formContainer">
                    <div class="upperSide">
                        <div class="sec1">
                            <p><b>First Name:</b></p>
                        </div>
                        
                        <div class="sec2">
                            <input type="text" id="box" name="FirstName">
                        </div>

                        <div class="sec3">
                            <p><b>Last Name:</b></p>
                        </div>

                        <div class="sec4">
                            <input type="text" id="box" name="LastName">
                        </div>
                    </div>
                    
                    <div class= "centre">
                        <div class="cLeft">
                            <p><b>Email</b></p>
                        </div>

                        <div class="cRight">
                            <input type="text" id="box" name="Email">
                        </div>
                    </div>

                    <div class= "centre" id="C2">
                        <div class="cLeft">
                            <p><b>Address</b></p>
                        </div>

                        <div class="cRight">
                            <textarea id="boxArea" row="5" name="Address"></textarea>
                        </div>
                    </div>

                    <div class= "centre">
                        <div class="cLeft">
                            <p><b>Photo</b></p>
                        </div>

                        <div class="cRight" id="cIMG">
                            <input type="file" name="Image" id="Image">
                        </div>
                    </div>

                    <div class="lowerSide">
                        <div class="lLeft">
                        <button type="reset"> cancel </button>
                        </div>

                        <div class="lRight">
                            <input type='submit' name='submit'>
                        </div>
                    </div>

                </div>
            </div>
        </form>

    </body>
</html>