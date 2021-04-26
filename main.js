const chk = document.getElementsByClassName('chk');

const sendData = (e) => {
    let color = e.target.value
    let accessToken = "23e679aa75372b8598fe26a15436cc450eb03692"

    Array.from(chk).forEach(element => {
        if(element.id !== color){
            element.checked = false
        }
    });

    axios.post(`https://api.particle.io/v1/devices/e00fce68ddbc34a9a32bb94a/ledColor?access_token=${accessToken}`, `arg=${color}`).then(res => {
        console.log('success')
    }).catch(err => {
        console.log(err)
    })    

}

red.addEventListener('click', sendData)
green.addEventListener('click', sendData)
blue.addEventListener('click', sendData)