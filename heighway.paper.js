
view._matrix.scale(1,-1);
view.center = new Point(0,0);

var position = new Point(0,0);

var lineLength = 10;

var compasses = [
	new Point(  0, lineLength),
	new Point(-lineLength,  0),
	new Point(  0,-lineLength),
	new Point( lineLength,  0)
];
var compass = 0;

var colors = [ "green", "blue", "red", "yellow"];
var color = 0;

var dragonArray = [];
var depth = 11;

while(depth--){
	var i = dragonArray.length;
	dragonArray.push(1,0);
	while(i-- > 0){
		if(dragonArray[i]) dragonArray.push( -dragonArray[i] );
	}
}

var dragon;
dragon = new Path();
dragon.strokeColor = colors[color];
dragon.add(position);

dragonArray.forEach(function(turn){
	if(turn == 0){
		color++;
		color%=colors.length;
		dragon = new Path();
		dragon.strokeColor = colors[color];
		dragon.add(position);

var marker = new Path.Circle(new Point( position.x - position.y, position.x + position.y ), 2);
marker.strokeColor = "orange";
marker.strokeWidth = 1;

console.log(position);
	}else{
		position = position + compasses[compass];
		dragon.add(position);
		compass = (compass+turn+4)%4;
	}
});

position = position + compasses[compass];
dragon.add(position);

console.log(position);

var marker = new Path.Circle(new Point( position.x - position.y, position.x + position.y ), 2);
marker.strokeColor = "orange";
marker.strokeWidth = 1;

// view._matrix.translate( -position.x/2 ,0)

// heighway.prototype.backdraw = function(){ this.p = this.nextend(); this.d=3; this.draw(this.size); }
// heighway.prototype.reset = function(){ this.p = {x:0,y:0}; }
