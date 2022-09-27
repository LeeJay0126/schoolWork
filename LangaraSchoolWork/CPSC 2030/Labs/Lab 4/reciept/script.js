
function calculate() {
    
    const price = Number(document.getElementById("price").value);
    const quantity = Number(document.getElementById("quantity").value);
    let subtotal = 0;

    for(let i = 1; i <= quantity; i++){
        if(i % 3 == 0){
            subtotal += (price/2);
        }else{
            subtotal += price;
        }
    }

    const pst = subtotal * 0.07;
    const gst = subtotal * 0.05;
    const total = subtotal + pst + gst;

    document.getElementById("subtotalDisplay").innerHTML = subtotal.toFixed(2);
    document.getElementById("gstDisplay").innerHTML = gst.toFixed(2);
    document.getElementById("pstDisplay").innerHTML = pst.toFixed(2);
    document.getElementById("totalDisplay").innerHTML = total.toFixed(2);

}