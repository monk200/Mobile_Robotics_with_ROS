;; Auto-generated. Do not edit!


(when (boundp 'cardriver::encoder)
  (if (not (find-package "CARDRIVER"))
    (make-package "CARDRIVER"))
  (shadow 'encoder (find-package "CARDRIVER")))
(unless (find-package "CARDRIVER::ENCODER")
  (make-package "CARDRIVER::ENCODER"))

(in-package "ROS")
;;//! \htmlinclude encoder.msg.html


(defclass cardriver::encoder
  :super ros::object
  :slots (_left _right _leftPos _rightPos ))

(defmethod cardriver::encoder
  (:init
   (&key
    ((:left __left) 0)
    ((:right __right) 0)
    ((:leftPos __leftPos) 0)
    ((:rightPos __rightPos) 0)
    )
   (send-super :init)
   (setq _left (round __left))
   (setq _right (round __right))
   (setq _leftPos (round __leftPos))
   (setq _rightPos (round __rightPos))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:leftPos
   (&optional __leftPos)
   (if __leftPos (setq _leftPos __leftPos)) _leftPos)
  (:rightPos
   (&optional __rightPos)
   (if __rightPos (setq _rightPos __rightPos)) _rightPos)
  (:serialization-length
   ()
   (+
    ;; int16 _left
    2
    ;; int16 _right
    2
    ;; int16 _leftPos
    2
    ;; int16 _rightPos
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _left
       (write-word _left s)
     ;; int16 _right
       (write-word _right s)
     ;; int16 _leftPos
       (write-word _leftPos s)
     ;; int16 _rightPos
       (write-word _rightPos s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _left
     (setq _left (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _right
     (setq _right (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _leftPos
     (setq _leftPos (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _rightPos
     (setq _rightPos (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get cardriver::encoder :md5sum-) "745db808f580869f3db96a00aaa84b88")
(setf (get cardriver::encoder :datatype-) "cardriver/encoder")
(setf (get cardriver::encoder :definition-)
      "int16 left
int16 right
int16 leftPos
int16 rightPos

")



(provide :cardriver/encoder "745db808f580869f3db96a00aaa84b88")


