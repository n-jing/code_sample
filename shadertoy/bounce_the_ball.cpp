#define PI 3.14159265359
#define R 0.15


float DistanceSphere(vec2 p, vec2 c, float r)
{
  return r / length(p-c);
}

float noise2d(vec2 p) {
	float t = texture(iChannel0, p);
	t += 0.5 * texture(iChannel0, p * 1.2);
	t += 0.25 * texture(iChannel0, p * 1.3);
	return t / 1.75;
}


void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
  vec2 uv = fragCoord.xy / iResolution.yy;

  float xdy = iResolution.x / iResolution.y;
  float HEIGHT = 1.0f - 2.0f * R;
  float WIDTH = xdy - 2.0f * R;
  
  vec2 c = vec2(0.5*xdy, 0.5);
  vec2 v = vec2(0.2f*xdy*0.7, 0.2f);
  c += iTime * v;

  ivec2 grid = ivec2(c.x/WIDTH, c.y/HEIGHT);
  c = vec2(mod(c.x, WIDTH), mod(c.y, HEIGHT));
  if (grid.x % 2 != 0)
    c.x = WIDTH - c.x;
  if (grid.y % 2 != 0)
    c.y = HEIGHT - c.y;
  c += R;
  
  vec2 p = (2.0*fragCoord.xy-iResolution.xy)/min(iResolution.y,iResolution.x);
  vec3 bg = vec3(1.0,0.8,0.7-0.07*p.y)*(1.0-0.25*length(p));
  float d = DistanceSphere(uv, c, R);
  fragColor = vec4(bg, 1.0f);

  float w = 0.025;
  if (d > 1.0 + w)
  {
    vec4 sg = vec4(0.624, 0.796, 0.361, 1.0);
    sg.rgb += noise2d(uv * 0.1) * 0.1;
    fragColor = sg;
  }
  else if (d > 1.0 - w)
  {
    fragColor = vec4(0.2, 0.2, 0.2, 1.0);
  }
  
  fragColor.rgb = pow(fragColor.rgb, vec3(1.0/2.2));
}
