const sendKey = require('./build/Release/sendKey');

module.exports = {
  keyUp: (n) => {
    sendKey.KeyUp(n);
  },
  keyDown: (n) => {
    sendKey.KeyDown(n);
  }
}