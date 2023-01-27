package com.springboot.chapter1.main;

import com.sun.deploy.net.HttpResponse;
import com.sun.jna.Library;
import com.sun.jna.Native;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletResponse;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

@SpringBootApplication
@Controller
public class Chapter1Main {
	
	public static void main(String[] args) {
		SpringApplication.run(Chapter1Main.class, args);
	}


	public interface Mydll extends Library {
		Mydll instance = Native.load("C:\\TestDll.dll", Mydll.class);

		int sum(int a,int b);

	}
	@RequestMapping("/")
	@ResponseBody
	public int dll(HttpServletResponse resp) {

		int ret=Mydll.instance.sum(1,2);
		resp.setHeader("Access-Control-Allow-Origin","*");

		return ret;
	}


}
