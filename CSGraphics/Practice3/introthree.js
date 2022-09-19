// Create the object to represent a triangle
function Triangle (a, aColor, b, bColor, c, cColor) {

    this.vertices = [
      a[0], a[1], a[2],
      b[0], b[1], b[2],
      c[0], c[1], c[2]
    ];

    this.colors = [
      aColor[0], aColor[1], aColor[2],
      bColor[0], bColor[1], bColor[2],
      cColor[0], cColor[1], cColor[2]
    ];
  
    // The function that actually adds the triangle geometry to the scene
    this.render = function() {
      // Create and assign the geometry
      this.geom = new THREE.BufferGeometry();  
      
      // Assign attributes to geometry
      this.geom.setAttribute( 'position', new THREE.BufferAttribute( new Float32Array(this.vertices), 3));
      this.geom.setAttribute( 'color' , new THREE.BufferAttribute( new Float32Array(this.colors), 3));

      this.material = new THREE.MeshBasicMaterial({ vertexColors: THREE.VertexColors });
      this.mesh = new THREE.Mesh( this.geom, this.material );

      scene.add(this.mesh);
    }	
  }


function Square(a, aColor, b, bColor, c, cColor, d, dColor) {

    this.vertices = [
      a[0], a[1], a[2],
      b[0], b[1], b[2],
      c[0], c[1], c[2],
      d[0], d[1], d[2]
    ];

    this.colors = [
      aColor[0], aColor[1], aColor[2],
      bColor[0], bColor[1], bColor[2],
      cColor[0], cColor[1], cColor[2],
      dColor[0], dColor[1], dColor[2]
    ];

     // The function that actually adds the triangle geometry to the scene
     this.render = function() {
        this.lowerTri = new Triangle(a, aColor, b, bColor, c, cColor);
        this.upperTri = new Triangle(a, aColor, c, cColor, d, dColor);

        this.lowerTri.render();
        this.upperTri.render();
    }	
    
}
  
var scene = new THREE.Scene();

var camera = new THREE.PerspectiveCamera( 35, window.innerWidth / window.innerHeight, .1, 3000 );
camera.position.z = 3;  // Try moving this around!
camera.lookAt( new THREE.Vector3(0.0,0.0,0.0));
scene.add( camera );

var renderer = new THREE.WebGLRenderer({canvas: myCanvas, antialias: true});
renderer.setClearColor(0x000000);
// If you want this to span the window, instead of using the myCanvas object, use the window object
renderer.setPixelRatio(document.getElementById('myCanvas').devicePixelRatio);
// If you want the render to span the window, uncomment this
//renderer.setSize(window.innerWidth, window.innerHeight);

var tri = new Triangle([0,0,0], [0.5,0,0], [0.5,0,0], [0,1.0,0], [0.5,0.5,0], [0,0,1.0] );
tri.render();

  
var square = new Square(
  [0.1,0.1,0], [0.5,0,0], 
  [0.3,0.1,0], [0,1.0,0], 
  [0.3,0.3,0], [0,1.0,1.0],
  [0.1,0.3,0], [1.0,0,1.0]);
square.render();

// Initiates graphical loop
animate();

function animate() {
   requestAnimationFrame(animate);
   render();
}

function render() {
  renderer.render( scene, camera );
  console.log('rendered');
}

var globalTranslateToggle = -1;

function keyHandler(e) {
  switch(e.keyCode) {
    case 83: // S key
      // ToDo
      tri.mesh.translateZ(globalTranslateToggle);
      globalTranslateToggle *= -1;
    break;  
  }
}

document.addEventListener( "keydown", keyHandler, false);


