; Auto-generated. Do not edit!


(cl:in-package cardriver-msg)


;//! \htmlinclude encoder.msg.html

(cl:defclass <encoder> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:fixnum
    :initform 0)
   (right
    :reader right
    :initarg :right
    :type cl:fixnum
    :initform 0)
   (leftPos
    :reader leftPos
    :initarg :leftPos
    :type cl:fixnum
    :initform 0)
   (rightPos
    :reader rightPos
    :initarg :rightPos
    :type cl:fixnum
    :initform 0))
)

(cl:defclass encoder (<encoder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <encoder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'encoder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cardriver-msg:<encoder> is deprecated: use cardriver-msg:encoder instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:left-val is deprecated.  Use cardriver-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:right-val is deprecated.  Use cardriver-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'leftPos-val :lambda-list '(m))
(cl:defmethod leftPos-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:leftPos-val is deprecated.  Use cardriver-msg:leftPos instead.")
  (leftPos m))

(cl:ensure-generic-function 'rightPos-val :lambda-list '(m))
(cl:defmethod rightPos-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cardriver-msg:rightPos-val is deprecated.  Use cardriver-msg:rightPos instead.")
  (rightPos m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <encoder>) ostream)
  "Serializes a message object of type '<encoder>"
  (cl:let* ((signed (cl:slot-value msg 'left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'right)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'leftPos)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'rightPos)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <encoder>) istream)
  "Deserializes a message object of type '<encoder>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'left) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'right) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'leftPos) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rightPos) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<encoder>)))
  "Returns string type for a message object of type '<encoder>"
  "cardriver/encoder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'encoder)))
  "Returns string type for a message object of type 'encoder"
  "cardriver/encoder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<encoder>)))
  "Returns md5sum for a message object of type '<encoder>"
  "745db808f580869f3db96a00aaa84b88")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'encoder)))
  "Returns md5sum for a message object of type 'encoder"
  "745db808f580869f3db96a00aaa84b88")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<encoder>)))
  "Returns full string definition for message of type '<encoder>"
  (cl:format cl:nil "int16 left~%int16 right~%int16 leftPos~%int16 rightPos~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'encoder)))
  "Returns full string definition for message of type 'encoder"
  (cl:format cl:nil "int16 left~%int16 right~%int16 leftPos~%int16 rightPos~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <encoder>))
  (cl:+ 0
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <encoder>))
  "Converts a ROS message object to a list"
  (cl:list 'encoder
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
    (cl:cons ':leftPos (leftPos msg))
    (cl:cons ':rightPos (rightPos msg))
))
