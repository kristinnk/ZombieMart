var building = {
  xTiles: 100,
  yTiles: 70,
  tiles: 0,
  
};


building.generate = function() {
	// Initial values (Predetermined now, but random late ron)

	// Empty the map  
	for (var i = 0; i < this.xTiles-1; i++) {
		for (var j = 0; j < this.yTiles-1; j++) {
	        building.tiles[i][j] = 0;
		}
	}
}

building.draw = function() {
	for (var i = 0; i < this.xTiles-1; i++) {
		for (var j = 0; j < this.yTiles-1; j++) {
            
		}
	}
}
