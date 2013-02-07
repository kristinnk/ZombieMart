var fontSprites = 0;


function loadText() {
	console.log("Loading text file.");
	fontSprites = new Image();
	fontSprites.src = "images/font_white_8x18.png";
}

function drawText(context, x, y, texti) { // basic black and white 8x16 text
	var text = { width: 8,
				 height: 16 }
				 //console.log(texti[0]);	
	for (var i = 0; i < texti.length; i++) {
		switch (texti[i]) {
			case 'a':
			case 'A': context.drawImage(fontSprites, 0, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
		    case 'b':
			case 'B': context.drawImage(fontSprites, 8, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'c':
			case 'C': context.drawImage(fontSprites, 16, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'd':
			case 'D': context.drawImage(fontSprites, 24, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'e':
			case 'E': context.drawImage(fontSprites, 32, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'f':
			case 'F': context.drawImage(fontSprites, 40, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'g':
			case 'G': context.drawImage(fontSprites, 48, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'h':
			case 'H': context.drawImage(fontSprites, 56, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'i':
			case 'I': context.drawImage(fontSprites, 64, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;		  					  			
			case 'j':
			case 'J': context.drawImage(fontSprites, 72, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'k':
			case 'K': context.drawImage(fontSprites, 80, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'l':
			case 'L': context.drawImage(fontSprites, 88, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'm':
			case 'M': context.drawImage(fontSprites, 96, 0, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'n':
			case 'N': context.drawImage(fontSprites, 0, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'o':
			case 'O': context.drawImage(fontSprites, 8, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'p':
			case 'P': context.drawImage(fontSprites, 16, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'q':
			case 'Q': context.drawImage(fontSprites, 24, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'r':
			case 'R': context.drawImage(fontSprites, 32, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 's':
			case 'S': context.drawImage(fontSprites, 40, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 't':
			case 'T': context.drawImage(fontSprites, 48, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'u':
			case 'U': context.drawImage(fontSprites, 56, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'v':
			case 'V': context.drawImage(fontSprites, 64, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'w':
			case 'W': context.drawImage(fontSprites, 72, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'x':
			case 'X': context.drawImage(fontSprites, 80, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'y':
			case 'Y': context.drawImage(fontSprites, 88, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case 'z':
			case 'Z': context.drawImage(fontSprites, 96, 16, 8, 16, x+(i*8), y, 8, 16);
					  break;

			case '1': context.drawImage(fontSprites, 0, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '2': context.drawImage(fontSprites, 8, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '3': context.drawImage(fontSprites, 16, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '4': context.drawImage(fontSprites, 24, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case '5': context.drawImage(fontSprites, 32, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '6': context.drawImage(fontSprites, 40, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '7': context.drawImage(fontSprites, 48, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '8': context.drawImage(fontSprites, 56, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case '9': context.drawImage(fontSprites, 64, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '0': context.drawImage(fontSprites, 72, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case '.': context.drawImage(fontSprites, 80, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case ':': context.drawImage(fontSprites, 88, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '<': context.drawImage(fontSprites, 96, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;			
			case '>': context.drawImage(fontSprites, 104, 32, 8, 16, x+(i*8), y, 8, 16);
					  break;

			case '@': context.drawImage(fontSprites, 0, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;					  			
			case '!': context.drawImage(fontSprites, 8, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case '?': context.drawImage(fontSprites, 16, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;
			case "'": context.drawImage(fontSprites, 24, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;		  
			case ',': context.drawImage(fontSprites, 32, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;		  
			case '(': context.drawImage(fontSprites, 40, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;			  
			case ')': context.drawImage(fontSprites, 48, 48, 8, 16, x+(i*8), y, 8, 16);
					  break;	

			default: break;
		}
	}
}