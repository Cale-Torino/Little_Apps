<!DOCTYPE html>
<html>
<head>
<title>Easter Egg</title>
<!-- Optional theme -->
<link rel="stylesheet" href="style.css">
<!-- Jquery -->
<script src="jquery.min.js"></script>
<!-- Latest compiled and minified JavaScript -->
<script src="bootstrap.min.js"></script>
</head>
<body onload="play()">
<h1>Easter Egg</h1>
<p>An example of Easter Eggs for your website.</p>
<p>
    <a href="javascript:var%20s%20=%20document.createElement('script');s.type='text/javascript';document.body.appendChild(s);s.src='http://localhost/eastereggs/extend/asteroids.min.js';void(0);" title="Spaceship">Spaceship</a>
    <a href="javascript:var%20s%20=%20document.createElement('script');s.type='text/javascript';document.body.appendChild(s);s.src='http://localhost/eastereggs/extend/bug.js';void(0);" title="Bug">Bug</a>
    <a href="javascript:var%20s%20=%20document.createElement('script');s.type='text/javascript';document.body.appendChild(s);s.src='http://localhost/eastereggs/extend/nyancat.js';void(0);" title="Nyancat">Nyancat</a> 
</p>
<script>
function play() {
    //var s = document.createElement('script');
    //s.type='text/javascript';
    //document.body.appendChild(s);
    //s.src='http://localhost/eastereggs/extend/asteroids.min.js';
    //void(0);
    console.log("http://localhost/eastereggs/extend/asteroids.min.js");
}
</script>
</body>
</html>