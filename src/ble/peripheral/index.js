var bleno = require('bleno');
var ToyHackService = require('./toyhack-service');
var GaburevolverService = require('./gaburevolver');
var MinityraService = require('./minityra');

var toyhackService = null;
var libname = process.argv[2];

if(libname === undefined){
  console.error('Module name is required.');
  process.exit(-1);
}
else if(libname.endsWith('/libgaburevolver.so')){
  toyhackService = new GaburevolverService(libname);
}
else if(libname.endsWith('/libminityra.so')){
  toyhackService = new MinityraService(libname);
}
else{
  console.error(libname + ' is not supported.');
  process.exit(-2);
}

console.log('ToyHack BLE proxy');

var primaryService = new bleno.PrimaryService({
  uuid: '36b50eb130c741a487a8b250e30fc000',
  characteristics: [
    new bleno.Characteristic({
      uuid: '36b50eb130c741a487a8b250e30fc001',
      properties: ['read'],
      value: new Buffer(toyhackService.getModuleName()),
      descriptors: [
        new bleno.Descriptor({
          uuid: '2901',
          value: 'Module name'
        })
      ]
    }),
    new bleno.Characteristic({
      uuid: '36b50eb130c741a487a8b250e30fc002',
      properties: ['read'],
      value: new Buffer(libname),
      descriptors: [
        new bleno.Descriptor({
          uuid: '2901',
          value: 'loaded library name'
        })
      ]
    })
  ]
});

bleno.on('stateChange', function(state) {
    if (state === 'poweredOn') {
        bleno.startAdvertising('ToyHack BLE proxy',
                         ['36b50eb130c741a487a8b250e30fb15d'], function(error){
            if (error) console.error(error);
        });
    } else {
        bleno.stopAdvertising();
    }
});

bleno.on('advertisingStart', function(error){
    if (!error) {
        console.log('Advertising has been started. Ready...');
        bleno.setServices([primaryService, toyhackService]);
    } else {
        console.error(error);
    }
});

