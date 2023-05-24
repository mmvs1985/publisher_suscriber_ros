#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
   // Este es el llamado a la función que inicializa el nodo y setea su nombre.
  ros::init(argc, argv, "publicador");

  //Esta es la variable con la cual se gestióna el nodo
  ros::NodeHandle n;

  //Aqui se setea la relacion entre el nodo y el topico, 
  //tambien el tipo de mensaje que va a soportar en este caso un String
  ros::Publisher topico_publicador = n.advertise<std_msgs::String>("topico_al_que_publico", 1000);

  //seteo el taza de repeticion que se va a repetir el envio del mensaje
  ros::Rate loop_rate(1);

  // uso un counter para darle unicidad al mensaje y controlar la cantidad de mensajes
  int counter = 0;
  std::stringstream ss;
  ss<<"No digas que no soy simpatico \n";
  while (counter<=10)
  {
    //Este es el objeto mensajes en el se guarda todo lo que debo enviar
    std_msgs::String msg;

    ss << "Hola Ricardo " << counter;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    //con esta funcion publico el mensje en el topico
    topico_publicador.publish(msg);
    //aqui solo limpio la el string
    ss.clear();
    ss.str(std::string());

    //esto ejecuta el callback que tenga el publicador
    ros::spinOnce();

    //y aqui hay un sleep para cumplir con la taza que se seteo previamente
    loop_rate.sleep();
    ++counter;
  }


  return 0;
}
