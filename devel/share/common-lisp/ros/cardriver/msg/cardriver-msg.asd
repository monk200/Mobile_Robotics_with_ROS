
(cl:in-package :asdf)

(defsystem "cardriver-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "encoder" :depends-on ("_package_encoder"))
    (:file "_package_encoder" :depends-on ("_package"))
    (:file "infrared" :depends-on ("_package_infrared"))
    (:file "_package_infrared" :depends-on ("_package"))
  ))