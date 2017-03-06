/*function NewtonClock(){
 var thisNC = this;
 this.tickDuration = 1;
 this.secondHand = null;
 this.time = 0;
 this.register = [];

 this.registerEvent = function(ticker, timing){
  thisNC.register.push([ticker,timing]);
 }
 this.tick = function(){
  thisNC.time++; for(var i=0; i<thisNC.register.length; i++){ if(!(thisNC.time%thisNC.register[i][1])){ thisNC.register[i][0](); } }; thisNC.secondHand = setTimeout(thisNC.tick,thisNC.tickDuration);
 }
 this.start = function(tickDuration, runtime){
  thisNC.runtime = runtime; setTimeout(thisNC.stop,thisNC.runtime); thisNC.tickDuration = tickDuration; thisNC.secondHand = setTimeout(thisNC.tick,thisNC.tickDuration);
 }
 this.stop = function(){
  clearTimeout(thisNC.secondHand);
 }
}
*/
function vector3(V_X,V_Y,V_Z,slate,moveable){ this.slate = slate; this.rep = null; this.x = V_X; this.y = V_Y; this.z = V_Z;
 var thisV = this; this.xi = 0; this.yi = 0;
 this.moveme = function(event){ thisV.x -= thisV.xi - event.clientX; thisV.y += thisV.yi - event.clientY; thisV.redrawVector(); thisV.xi = event.clientX; thisV.yi = event.clientY; ess.updateStep(); }
 if(slate!=null){ this.rep = this.drawVector(); if(moveable){
   this.rep.addEventListener('mousedown', function(event) { document.addEventListener('mousemove',thisV.moveme,false); thisV.xi = event.clientX; thisV.yi = event.clientY; }, false);
   this.rep.addEventListener('mouseup', function(event) { document.removeEventListener('mousemove',thisV.moveme,false); }, false);
 } }
}
 vector3.prototype.add = function(secondVector){ this.x += secondVector.x; this.y += secondVector.y; this.z += secondVector.z; }
 vector3.prototype.subtract = function(secondVector){ this.x -= secondVector.x; this.y -= secondVector.y; this.z -= secondVector.z; }
 vector3.prototype.copyVector = function(){ return new vector3(this.x,this.y,this.z); }
 vector3.prototype.drawVector = function(V_radius,V_strokewidth,V_stroke,V_fill){ return this.slate.ellipse(V_radius||4,V_radius||4,this.x,this.y,V_stroke||'black',V_strokewidth||'1px', V_fill||'white'); }
 vector3.prototype.redrawVector = function(){ this.rep.moveTo(this.x,this.y); }

function addVectors(firstVector,secondVector){ return new vector3( firstVector.x+secondVector.x , firstVector.y+secondVector.y , firstVector.z+secondVector.z ); };
function subtractVectors(firstVector,secondVector){ return new vector3( (firstVector.x-secondVector.x) , (firstVector.y-secondVector.y) , (firstVector.z-secondVector.z) ); };

//function springPoint(baseVector,endVector,springConstant,clock){
// this.base = baseVector; this.end = endVector; this.dV = baseVector.copyVector(); this.k = springConstant; //this.clock = clock;
//}
// springPoint.prototype.updateStep = function(){
//  this.end.add(subtractVectors(this.base,this.dV)); this.dV = this.base.copyVector();
//  if(this.base.rep!=null){ this.base.redrawVector(); }; if(this.end.rep!=null){ this.end.redrawVector(); }
//  setTimeout(ess.updateStep(),100);
// }