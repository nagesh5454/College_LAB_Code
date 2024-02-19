function playSound(animal) {
    var audio = document.getElementById('animal-sound');
    
    
    switch(animal) {
      case 'cat':
        audio.src = 'cat-sound.mp3';
        break;
      case 'dog':
        audio.src = 'dog-sound.mp3';
        break;
      case 'elephants':
        audio.src = 'elephant.mp3';
        break;
     case 'tiger':
        audio.src = 'bengal_tiger.mp3';
        break;
        case 'bear':
        audio.src = 'bear.mp3';
        break;
        case 'lion':
        audio.src = 'lion.mp3';
        break;
      default:
        audio.src = '';
    }
  
 
    audio.play();
  }
  
  