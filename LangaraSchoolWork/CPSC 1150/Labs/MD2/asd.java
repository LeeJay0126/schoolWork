int validator = 1;
String str = "";
String temp = "";
for(int i = 0; i < words.length; i ++){
	validator = 0;
	str = words[i];
	for(int k = 0; k < str.length(); k++){
		
		if(str.substring(k,1) == letter){
			validator = 1;
		}
		
	}
	if(validator = 1){
		
		str = null;
		
	}
	
}

for(int d = 0;d < words.length; d ++){
	str = words[i];
	for(int f = 0; f < words.length-1; f++){
		
		if(str == null){
			temp = words[i];
			words[i] = words[i+1];
			words[i+1] = words[i];
		}
		
	}
	
}

return words;