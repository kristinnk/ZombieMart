var FPS;
var canvasElement;
var canvas;

function draw() {
  canvas.fillStyle = "#111";
  canvas.fillRect(0, 0, canvasElement.width, canvasElement.height);
  map.draw();
}

function update() {
    if (keydown.left) {
    }
}

function gameLoop() {	
    update();
    draw();
    requestAnimFrame(function(){
        gameLoop();
    })
}

window.onload = function() {	
  console.log('Loading variables.');
  canvasElement = document.getElementById("mainCanvas");
	canvas = canvasElement.getContext("2d");  


  console.log("Entering the game loop");
  gameLoop();	
}


// Animation frame shim
window.requestAnimFrame = (function(){
      return  window.requestAnimationFrame       || 
              window.webkitRequestAnimationFrame || 
              window.mozRequestAnimationFrame    || 
              window.oRequestAnimationFrame      || 
              window.msRequestAnimationFrame     || 
              function( callback ){
                window.setTimeout(callback, 1000 / 60);
              };
    })();
