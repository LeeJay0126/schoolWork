let myObject = {
    height : 100,
    width : 200,
    clone : function(){
        return { height: this.height, width: this.width, clone:this.clone};
    }
}

let yourObject = myObject.clone();
let theirObject = myObject;