#include <iostream>
#include <memory>
using namespace std;

class Shader{
	string name;
	string type;

public:

	Shader(string name, string type){
		this->name=name;
		this->type=name;
		cout << "Shader Complied" << endl;
	}

	int getRefernceCount(shared_ptr<Shader> shader) {
		    return shader.use_count();
	}

	~Shader(){
		cout << "Shader Destroyed" << endl;
	}

};

int main2(){

	auto shader = make_shared<Shader>("main_vert","vertex");
	cout << "Ref count: " << shader->getRefernceCount(shader)<< endl;
	{
	auto rendererRef = shader;
	cout << "Ref count: " << shader->getRefernceCount(shader)<< endl;

	auto editorRef = shader;
	cout << "Ref count: " << shader->getRefernceCount(shader)<< endl;
	}
	cout << "Ref count: " << shader->getRefernceCount(shader)<< endl;

	return 0;
}
