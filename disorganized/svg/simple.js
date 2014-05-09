
function heighway(settings){
 this.defaults = {
	debug: false,
	stride: 10,
	p: {x:0,y:0},
	pOld: {x:0,y:0},
	d: 0,
	h: []
 }
 this.initialize(settings);
}

heighway.prototype.draw = function(){
 for(var i=0,l=this.h.length; i<l; i++){
	this.pOld.x = this.p.x;
	this.pOld.y = this.p.y;
	this.p.x += this.compass[this.d].x;
	this.p.y += this.compass[this.d].y;
	this.svg.line(this.pOld.x,this.pOld.y,this.p.x,this.p.y,'black');
	this.d += (this.h[i]==0?1:3);
	this.d %= 4;
 }
}

heighway.prototype.drawFrom = function(point,direction){ this.p = point; this.d = direction; this.draw(); }

heighway.prototype.doStep = function(){
 var l=this.h.length-1;
 while(l>0) this.h.push(1-this.h[--l]);
 this.h.push(0);
}

heighway.prototype.doSteps = function(nSteps){
 while(nSteps--){ this.doStep(); if(this.showIntermediateSteps) this.hstep.push(this.h.length +': '+ this.h.join('')); }
 if(this.showIntermediateSteps) this.host.body.innerHTML = this.hstep.join('<br />\n');
}

heighway.prototype.initialize = function(settings){
 try{
	for(var i in this.defaults) this[i] = (!!settings[i]?settings[i]:this.defaults[i]);
	this.compass = [{x:0,y:this.stride},{x:this.stride,y:0},{x:0,y:-this.stride},{x:-this.stride,y:0}];
	if(!document) throw new Error('Why there be no document!?  WHY???')
	this.host = { body: document.body, width: (.98*window.innerWidth), height: (.98*window.innerHeight) }
	this.host.halfHeight = Math.round(this.host.height/2); this.host.halfWidth = Math.round(this.host.width/2);
	if(this.debug){
	 this.hstep = [];
	 this.bug = new debug_box(this.host.body,'comment');
	 this.showIntermediateSteps = true;
	}else{
	 if(!SVG_Element) throw new Error('SVG Library not found.')
	 this.svg = new SVG_Element(this.host.body,'svg_frame','-'+this.host.halfWidth+' -'+this.host.halfHeight+' '+this.host.width+' '+this.host.height);
	}
 }catch(ex){
	var txt=[ex]; for(var i in ex) txt.push(i+': '+ex[i]);
	alert('Could not initialize:'+ txt.join('\n') );
 }
}
