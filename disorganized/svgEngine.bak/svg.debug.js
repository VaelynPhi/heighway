
// BEGIN debugBox

function debugBox(parentElement, className){
	if(typeof($) != "function"){ alert("There is no jQuery, only Zool."); return; }

	var me = this;
	this.parentElement = parentElement;

	$(this.parentElement).append(
		this.content = $(document.createElement("div"))
	);
	$(this.content).addClass(className);
	// this.say();
}

// prototype constructor methods.
debugBox.prototype.clear = function(){
	$(this.content).empty();
}

debugBox.prototype.addHTML = function(tagType){
	$(this.div).append(document.createElement(tagType));
}

debugBox.prototype.add = function(comment_text, comment_break){
	if(comment_break==null){
		this.div.appendChild(document.createElement("br"));
	}
	this.div.appendChild(document.createTextNode(comment_text));
}

debugBox.prototype.say = function(comment_text){
	if(comment_text==null){ comment_text = "Debug Area."; }
	this.clear();
	this.add(comment_text);
}

// END debugBox
