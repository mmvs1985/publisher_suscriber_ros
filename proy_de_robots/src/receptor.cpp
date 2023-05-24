#include "ros/ros.h"
#include "std_msgs/String.h"

void funcionCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("He recibido este mensaje: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Este es el llamado a la función que inicializa el nodo y setea su nombre.
  ros::init(argc, argv, "receptor");

  //Esta es la variable con la cual se gestióna el nodo
  ros::NodeHandle n;

  //Aqui se setea la suscripcion entre el nodo y el topico,
  //tambien el tamaño de la cola de buffer para esperar a ser procesado 
  //y la funcion que procesa el mensaje
  ros::Subscriber sub = n.subscribe("topico_al_que_publico", 1000, funcionCallback);

  //esta funcion hace que el nodo siga escuchando hasta que muera el master o se mate este proceso
  ros::spin();

  return 0;
}
