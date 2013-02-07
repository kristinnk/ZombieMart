var best_cell = { x: 0, 
				  y: 0, 
				  dist: 99999 
				};

var enemy_box = {
	x: 0,
	y: 0,
	width: 0,
	height: 0
};			

var misc_tile = {
	x: 0,
	y: 0,
	width: 0,
	height: 0
};			

var text_duration_counter = 0;

function distance(a, b) {
	var dX = Math.abs(a.x - b.x);
	var dY = Math.abs(a.y - b.y);
	var dist = Math.sqrt(Math.pow(dX, 2)+Math.pow(dY, 2));
	return dist;
}

function collides(a, b) {
  return a.x < b.x + b.width &&
         a.x + a.width > b.x &&
         a.y < b.y + b.height &&
         a.y + a.height > b.y;
}
