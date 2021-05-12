
class simpleSynth {

   constructor() {
      this.audioContext = false;
      this.freqlist = {
         "A": 440.0,
         "B": 493.9,
         "C": 523.3,
         "D": 587.3,
         "E": 622.3,
         "F": 698.5,
         "G": 784.0
      }

   }
   setup() {
      const numNotes = 7;
  

      //Audio filter chain setup
      this.audioContext = new (window.AudioContext || window.webkitAudioContext);
      this.volumeControl = this.audioContext.createGain();
      this.volumeControl.connect(this.audioContext.destination);
      this.volumeControl.gain.value = 1;

   }
   
   async playNote(note, duration = 250) {
      const pauseDuration = 10;
      return new Promise((res, rej) => {
         if (!this.audioContext) {
            this.setup();
         }
         if (!this.freqlist.hasOwnProperty(note)) {
            console.log("Note not found");
            res(false)
         }
         let waveForm = this.audioContext.createOscillator();
         waveForm.frequency.value = this.freqlist[note];
         waveForm.type = "sine";
         waveForm.connect(this.volumeControl);
         waveForm.start();

         setTimeout(() => {
            waveForm.stop();
            setTimeout(()=>{
               res(true)
            },pauseDuration)
         }, duration)
      })

   }
}




var synth = new simpleSynth();