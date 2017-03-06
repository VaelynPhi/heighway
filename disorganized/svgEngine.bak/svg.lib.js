
function svgElement(parentElement,xrange,yrange,xcorner,ycorner){
	this.parentElement = parentElement;
	this.svgNode = this.addSVG("svg");
	this.svgNode.setAttribute("xmlns",this.xmlNS);
	this.setViewBox(xrange,yrange,xcorner,ycorner);
	this.g = this.addSVG("g");
	this.svgNode.appendChild(this.g);
	this.g.setAttribute("transform","scale(1,-1)");
	this.parentElement.appendChild(this.svgNode);
}

// Begin prototype constructor methods.
svgElement.prototype.svgNS = "http://www.w3.org/2000/svg";
svgElement.prototype.xmlNS = "http://www.w3.org/2000/svg";
svgElement.prototype.getElement = function(element_id){ return document.getElementById(element_id); }
svgElement.prototype.add = function(element_type){ return document.createElement(element_type); }
svgElement.prototype.addSVG = function(svg_elem){ return (document.createElementNS(this.svgNS,svg_elem)); }
svgElement.prototype.textNode = function(text_string){ return document.createTextNode(text_string); }
svgElement.prototype.random_color = function(max_value){
	if(max_value==null){ max_value = 255; };
	return Math.floor(max_value*Math.random());
}

svgElement.prototype.setClass = function(className){
	this.svgNode.setAttribute("class", className );
}

svgElement.prototype.setViewBox = function(xrange,yrange,xcorner,ycorner){
	if(!xrange) alert("Failure to set view box: no range supplied.");
	xrange = 2*xrange;
	if(!yrange) yrange = xrange;
	if(!xcorner) xcorner = -(xrange/2);
	if(!ycorner) ycorner = -(yrange/2);
	this.viewBox = { range: { x: xrange, y: yrange }, corner: { x: xcorner, y: ycorner } };
	// this.viewBoxString = xrange +" "+ yrange +" "+ xcorner +" "+ ycorner;
	this.viewBoxString = xcorner +" "+ ycorner +" "+ xrange +" "+ yrange;
	console.log(this.viewBoxString);
	this.svgNode.setAttribute("viewBox", this.viewBoxString );
}

svgElement.prototype.move = function(xd,yd){};

svgElement.prototype.polygon = function(polygon_points,polygon_fill,polygon_stroke,polygon_stroke_width){
	if(polygon_stroke==null){ polygon_stroke = "black"; };
	if(polygon_stroke_width==null){ polygon_stroke_width = "1px"; };
	if(polygon_fill==null){ polygon_fill = "none"; };
//   if( polygon_points ){
		var polygon_points_string = ""; for(var i=0; i<polygon_points.length; i++){ polygon_points_string += polygon_points[i] + " "; };
//   };
	var polygon_new = this.addSVG("polygon");
	polygon_new.setAttribute("stroke",polygon_stroke);
	polygon_new.setAttribute("stroke-width",polygon_stroke_width);
	polygon_new.setAttribute("fill",polygon_fill);
	polygon_new.setAttribute("points",polygon_points_string);
	this.g.appendChild(polygon_new); return polygon_new;
}

svgElement.prototype.moveEllipse = function(mx,my){ if(mx==null){ mx = this.getAttribute("cx"); }; if(my==null){ my = this.getAttribute("cy"); }; this.setAttribute("cx",mx); this.setAttribute("cy",my); }

svgElement.prototype.ellipse = function(ellipse_A,ellipse_B,ellipse_cx,ellipse_cy,ellipse_stroke,ellipse_stroke_width,ellipse_fill){
	if(ellipse_stroke==null){ ellipse_stroke = "black"; };
	if(ellipse_stroke_width==null){ ellipse_stroke_width = "1px"; };
	if(ellipse_fill==null){ ellipse_fill = "none"; };
	var ellipse_new = this.addSVG("ellipse");
	ellipse_new.setAttribute("stroke",ellipse_stroke);
	ellipse_new.setAttribute("stroke-width",ellipse_stroke_width);
	ellipse_new.setAttribute("rx",ellipse_A);
	ellipse_new.setAttribute("ry",ellipse_B);
	ellipse_new.setAttribute("cx",ellipse_cx);
	ellipse_new.setAttribute("cy",ellipse_cy);
	ellipse_new.setAttribute("fill",ellipse_fill);
	ellipse_new.moveTo = this.moveEllipse;

	this.g.appendChild(ellipse_new); return ellipse_new;
}

svgElement.prototype.circle = function(circle_R,circle_cx, circle_cy, circle_stroke, circle_stroke_width, circle_fill){
	return this.ellipse(circle_R,circle_R,circle_cx,circle_cy, circle_stroke, circle_stroke_width, circle_fill)
}

svgElement.prototype.line = function(line_x_init,line_y_init,line_x_fini,line_y_fini,line_stroke,line_stroke_width){
	if(line_stroke==null){ line_stroke = "black"; };
	if(line_stroke_width==null){ line_stroke_width = "1px"; };
	var line_new = this.addSVG("line");
	line_new.setAttribute("x1",line_x_init);
	line_new.setAttribute("y1",line_y_init);
	line_new.setAttribute("x2",line_x_fini);
	line_new.setAttribute("y2",line_y_fini);
	line_new.setAttribute("stroke",line_stroke);
	line_new.setAttribute("stroke-width",line_stroke_width);
	this.g.appendChild(line_new); return line_new;
}

svgElement.prototype.square = function(square_side,square_cx,square_cy,square_stroke,square_stroke_width,square_fill){
	var square_new = this.rect(square_side,square_side,square_cx,square_cy,square_stroke,square_stroke_width,square_fill);
	this.g.appendChild(square_new); return square_new;
}

svgElement.prototype.rect = function(rect_x_side,rect_y_side,rect_cx,rect_cy,rect_stroke,rect_stroke_width,rect_fill){
	if(rect_stroke==null){ rect_stroke = "black"; };
	if(rect_stroke_width==null){ rect_stroke_width = "1px"; };
	if(rect_fill==null){ rect_fill = "none"; };

	var rect_new = this.addSVG("rect");
	rect_new.setAttribute("width",rect_x_side);
	rect_new.setAttribute("height",rect_y_side);
	rect_new.setAttribute("x",rect_cx);
	rect_new.setAttribute("y",rect_cy);
	rect_new.setAttribute("stroke",rect_stroke);
	rect_new.setAttribute("stroke-width",rect_stroke_width);
	rect_new.setAttribute("fill",rect_fill);
	this.g.appendChild(rect_new); return rect_new;
}

//End svgElement
