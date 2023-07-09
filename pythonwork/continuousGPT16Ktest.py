import openai
openai.api_key = "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"
fin=open("text.txt","w")
s_in=fin.read()

completion = openai.ChatCompletion.create(
  model="gpt-3.5-turbo",
  messages=
  """[
    {"role": "system", "content": "You are a helpful assistant."},
    {"role": "user", "content": "你好"}
  ]"""
)

f=open("gpt16k临时回答.txt","w")
s=str(completion.choices[0].message["content"])#.decode("unicode-escape")
f.write(s)
f.close()
