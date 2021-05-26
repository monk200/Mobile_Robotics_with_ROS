// Auto-generated. Do not edit!

// (in-package cardriver.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class encoder {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left = null;
      this.right = null;
      this.leftPos = null;
      this.rightPos = null;
    }
    else {
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = 0;
      }
      if (initObj.hasOwnProperty('right')) {
        this.right = initObj.right
      }
      else {
        this.right = 0;
      }
      if (initObj.hasOwnProperty('leftPos')) {
        this.leftPos = initObj.leftPos
      }
      else {
        this.leftPos = 0;
      }
      if (initObj.hasOwnProperty('rightPos')) {
        this.rightPos = initObj.rightPos
      }
      else {
        this.rightPos = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type encoder
    // Serialize message field [left]
    bufferOffset = _serializer.int16(obj.left, buffer, bufferOffset);
    // Serialize message field [right]
    bufferOffset = _serializer.int16(obj.right, buffer, bufferOffset);
    // Serialize message field [leftPos]
    bufferOffset = _serializer.int16(obj.leftPos, buffer, bufferOffset);
    // Serialize message field [rightPos]
    bufferOffset = _serializer.int16(obj.rightPos, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type encoder
    let len;
    let data = new encoder(null);
    // Deserialize message field [left]
    data.left = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [right]
    data.right = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [leftPos]
    data.leftPos = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [rightPos]
    data.rightPos = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'cardriver/encoder';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '745db808f580869f3db96a00aaa84b88';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 left
    int16 right
    int16 leftPos
    int16 rightPos
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new encoder(null);
    if (msg.left !== undefined) {
      resolved.left = msg.left;
    }
    else {
      resolved.left = 0
    }

    if (msg.right !== undefined) {
      resolved.right = msg.right;
    }
    else {
      resolved.right = 0
    }

    if (msg.leftPos !== undefined) {
      resolved.leftPos = msg.leftPos;
    }
    else {
      resolved.leftPos = 0
    }

    if (msg.rightPos !== undefined) {
      resolved.rightPos = msg.rightPos;
    }
    else {
      resolved.rightPos = 0
    }

    return resolved;
    }
};

module.exports = encoder;
